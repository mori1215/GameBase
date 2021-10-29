#include "TitleScene.h"
#include <Mof.h>

using namespace Game;

//コンストラクタ
TitleScene::TitleScene()
{
}

//デストラクタ
TitleScene::~TitleScene()
{
}

//読み込み
bool Game::TitleScene::Load()
{
    return false;
}

//初期化
void TitleScene::Initialize()
{
}

//更新
void TitleScene::Update()
{
}

//描画
void TitleScene::Render()
{
    CGraphicsUtilities::RenderString(0, 0, "タイトルシーン");
}

//解放
void TitleScene::Release()
{
}
