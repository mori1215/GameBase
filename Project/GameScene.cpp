#include "GameScene.h"
#include <Mof.h>

using namespace Game;

//コンストラクタ
GameScene::GameScene()
{
}

//デストラクタ
GameScene::~GameScene()
{
}

//読み込み
bool GameScene::Load()
{
    return false;
}

//初期化
void GameScene::Initialize()
{
}

//更新
void GameScene::Update()
{
}

//描画
void GameScene::Render()
{
    CGraphicsUtilities::RenderString(0, 0, "ゲームシーン");
}

//解放
void GameScene::Release()
{
}
