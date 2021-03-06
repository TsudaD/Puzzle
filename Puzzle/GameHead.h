#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	OBJ_BLOCK,
	OBJ_BLOCK_2,
	OBJ_FREEZE_BLOCK,
	OBJ_TITLE_BACK_GROUND,
	OBJ_RESULT_BACK_GROUND,
	OBJ_MAP,
	OBJ_MAP_PLAY2,
	OBJ_NEXT_BLOCK,
	OBJ_NEXT_BLOCK_2,
};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	
};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--



//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include "Cblock.h"
#include "CTitleBackGround.h"
#include "CResultBackGround.h"
#include "CConnectBackGround.h"
#include "CMap.h"
#include "CFreezeblock.h"
#include "CNextBlock.h"
//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include "CSceneMain.h"
#include "CSceneTitle.h"
#include "CSceneResult.h"
#include "CSceneConnect.h"
//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START CSceneTitle
//-----------------------------------------------