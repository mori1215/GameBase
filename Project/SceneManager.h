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
		//�G�t�F�N�g�����t���O
		bool effectInStart;
		bool effectOutStart;
		bool effectStart;
		//�V�[���G�t�F�N�g���s�t���[��
		int waitCount;
		//�V�[���G�t�F�N�g�J�E���g
		int effectCount;

	public:
		//�R���X�g���N�^
		SceneManager();
		//�f�X�g���N�^
		~SceneManager();
		//������
		void Initialize(int sceneNo,int wait);
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


