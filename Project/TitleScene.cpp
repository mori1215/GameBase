#include "TitleScene.h"
#include <Mof.h>
#include "GameDefine.h"

using namespace Game;

//�R���X�g���N�^
TitleScene::TitleScene()
{
}

//�f�X�g���N�^
TitleScene::~TitleScene()
{
}

//�ǂݍ���
bool Game::TitleScene::Load()
{
    return false;
}

//������
void TitleScene::Initialize()
{
}

//�X�V
void TitleScene::Update()
{
    //Enter�L�[�ŃQ�[����ʂ�
    if (g_pInput->IsKeyPush(MOFKEY_RETURN))
    {
        changeFlag = true;
        nextScene = SceneName_Game;
    }
}

//�`��
void TitleScene::Render()
{
    CGraphicsUtilities::RenderString(0, 0, "�^�C�g���V�[��");
}

//���
void TitleScene::Release()
{
}
