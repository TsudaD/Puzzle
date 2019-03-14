//STLデバック機能をOFFする
#define _SECURE_SCL (0)
#define _HAS_IETRATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "GameHead.h"

//コンストラクタ
CSceneResult::CSceneResult()
{

}

//デストラクタ
CSceneResult::~CSceneResult()
{

}

//初期化メソッド
void CSceneResult::InitScene()
{
	// 背景オブジェクトの代わりの画像(差し換えてください(涙))
	Draw::LoadImageW(L"block.png", 0, TEX_SIZE_32);

	// リザルト画面背景オブジェクト
	CResultBackGround* p_result_back_ground = new CResultBackGround;
	Objs::InsertObj(p_result_back_ground, OBJ_RESULT_BACK_GROUND, 0);
}

//実行中メソッド
void CSceneResult::Scene()
{

}