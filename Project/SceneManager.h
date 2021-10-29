#pragma once
#include "SceneBase.h"

namespace Game
{
	//�V�[���Ǘ��N���X
	class SceneManager
	{
	private:
		//���ݎ��s����Ă���V�[��
		ScenePtr currentScene;
		//�ύX����������V�[��
		ScenePtr nextScene;
		int nextScene;

	public:
		//�R���X�g���N�^
		SceneManager();
		//�f�X�g���N�^
		~SceneManager();
		//������
		void Initialize(int sceneNo);
		//�X�V
		void Update();
		//�`��
		void Render();
		//���
		void Release();
		//�V�[���̐���
		ScenePtr Create(int sceneNo);
	};
}


