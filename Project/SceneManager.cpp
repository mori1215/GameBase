#include "SceneManager.h"
#include "GameDefine.h"
#include <Mof.h>

//�e�V�[����include
#include "TitleScene.h"
#include "GameScene.h"

using namespace Game;

//�R���X�g���N�^
SceneManager::SceneManager()
	: currentScene(nullptr),
	nextScene(nullptr),
	effectInStart(true),
	effectOutStart(false),
	effectStart(true),
	effectCount(0),
	waitCount(30)
{
}

//�f�X�g���N�^
SceneManager::~SceneManager()
{
}

//������
void SceneManager::Initialize(int sceneNo,int wait)
{
	Release();
	waitCount = wait;
	effectCount = 0;
	effectInStart = false;
	effectOutStart = true;

	//�����V�[���̐���
	currentScene = Create(sceneNo);
	if(currentScene == nullptr)
	{
		MOF_PRINTLOG("Scene Create Failured\n");
		return;
	}

	//�ǂݍ��ݎ��s�����ꍇ�G���[���O���c��
	if (!currentScene->Load())
	{
		MOF_PRINTLOG("Scene Create Failured\n");
		return;
	}
	
	currentScene->Initialize();
}

//�X�V
void SceneManager::Update()
{
	//�V�[�������ł��Ă��Ȃ��ꍇ�A�X�V���Ȃ�
	if (!currentScene)
	{
		return;
	}

	if (effectInStart)
	{
		effectCount++;
		if (effectCount >= waitCount * 0.5)
		{
			effectInStart = false;
			effectOutStart = true;
		}
	}
	else if (effectOutStart)
	{
		effectCount++;
		if (effectCount >= waitCount)
		{
			effectCount = 0;
			effectOutStart = false;
		}
	}
	else if (effectStart)
	{
		effectStart = false;
	}

	//�V�[���̍X�V
	currentScene->Update();
	//�V�[���̕ύX
	if (currentScene->IsChange())
	{
		if (!effectStart)
		{
			effectStart = true;
			effectInStart = true;
			effectOutStart = false;
		}
		if (effectOutStart)
		{
			//���̃V�[���̎擾
			int next = currentScene->GetNextScene();
			//�擾�����V�[���̐���
			nextScene = Create(next);
			if (nextScene)
			{
				//�V�[���̓ǂݍ���
				nextScene->Load();
				//�V�[��������
				nextScene->Initialize();
			}
			//����Ȃ��Ȃ����Â��V�[��������
			currentScene->Release();
			currentScene.reset();
			//�V�����V�[����p��
			currentScene = nextScene;
			nextScene = nullptr;
			effectStart = false;
		}		
	}
}

//�`��
void SceneManager::Render()
{
	//�V�[�������ł��Ă��Ȃ��ꍇ�A�`�悵�Ȃ�
	if (!currentScene)
	{
		return;
	}
	//�V�[���̕`��
	currentScene->Render();

	CRectangle fadeRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight());
	if (effectInStart)
	{
		float alpha = effectCount / (waitCount * 0.5f);
		CGraphicsUtilities::RenderFillRect(fadeRect, MOF_ALPHA_BLACK((int)(255 * alpha)));
	}
	else if (effectOutStart)
	{
		float alpha = (effectCount - (waitCount * 0.5f)) / (waitCount * 0.5f);
		CGraphicsUtilities::RenderFillRect(fadeRect, MOF_ALPHA_BLACK((int)(255 * (1.0f - alpha))));
	}
}

//���
void SceneManager::Release()
{
	if (currentScene)
	{
		currentScene->Release();
		currentScene.reset();
	}

	if (nextScene)
	{
		nextScene->Release();
		nextScene.reset();
	}
}

//�V�[���̐���
ScenePtr SceneManager::Create(int sceneNo)
{
	switch (sceneNo)
	{
	case SceneName_Title:
		return std::make_shared<TitleScene>();
	case SceneName_Game:
		return std::make_shared<GameScene>();
	default:
		break;
	}
	return ScenePtr();
}
