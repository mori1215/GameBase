#pragma once
#include <memory>

namespace Game
{
	//シーンの基底クラス
	class SceneBase
	{
	protected:
		//シーンの変更フラグ
		bool changeFlag; 
		//変更先シーン
		int nextScene;   

	public:
		//デストラクタ
		virtual ~SceneBase() = default;

		//読み込み
		virtual bool Load() = 0;
		//初期化
		virtual void Initialize() = 0;
		//更新
		virtual void Update() = 0;
		//描画
		virtual void Render() = 0;
		//解放
		virtual void Release() = 0;

		//シーン変更フラグ
		bool IsChange() const noexcept
		{
			return changeFlag;
		}

		int GetNextScene() const noexcept
		{
			return nextScene;
		}		
	};

	//ポインタ名の置き換え
	using ScenePtr = std::shared_ptr<SceneBase>;
}

