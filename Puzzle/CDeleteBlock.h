#pragma once

//使用するヘッダー
#include "GameL/SceneObjManager.h"
#include "Cblock.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：消せるブロック
class CDeleteBlock : public Cblock
{
	public:
		CDeleteBlock(int num);
		~CDeleteBlock() {};
		void Init();
		void Action();
		void Draw();

	private:
		float m_fPx;//位置X
		float m_fPy;//位置Y
		float m_fVx;//Xベクトル
		float m_fVy;//Yベクトル

		bool m_bStop_flag;//ブロック停止フラグ
		bool m_a_key_push;//aキーの長押し入力防止フラグ
		bool m_d_key_push;//dキーの長押し入力防止フラグ

		int m_bColornum;//ブロックの色
};