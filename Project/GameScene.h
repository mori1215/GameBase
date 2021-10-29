#pragma once
#include "SceneBase.h"

namespace Game
{
	//�^�C�g���V�[���N���X
	class GameScene : public SceneBase
	{
	public:
		//�R���X�g���N�^
		GameScene();
		//�f�X�g���N�^
		virtual ~GameScene() = default;

		//�ǂݍ���
		virtual bool Load() override;
		//������
		virtual void Initialize() override;
		//�X�V
		virtual void Update() override;
		//�`��
		virtual void Render() override;
		//���
		virtual void Release() override;
	};
}