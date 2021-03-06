#pragma once

//使用するヘッダー
#include"GameL/SceneObjManager.h"

#include "CNextBlock.h"
#include "CMap.h"

//使用するネームスペース
using namespace GameL;

//クラスオブジェクト：ブロック
class Cblock : public CObj
{
	public:
		Cblock(int num,float fPosX, CNextBlock* pNextBlock, CMap* pMap);
		~Cblock() {};
		void Init();
		void Action();
		void Draw();
		bool Getblock_fall() { return m_block_fall_ok; };

		// 移動処理
		void Move(int nKey_Code);

	protected:
		float m_fPx;//位置X
		float m_fPy;//位置Y
		float m_fVx;//Xベクトル
		float m_fVy;//Yベクトル

		bool m_bStop_flag;//ブロック停止フラグ
		bool m_Again_fall_on;
		bool m_block_fall_ok;

		int m_bColornum;//ブロックの色
		int m_elementX_storage;//ブロックの要素番号Xの保存
		int m_elementY_storage;//ブロックの要素番号Yの保存

		CNextBlock* m_pNextBlock;
		CMap*		m_pMap;
};