//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameL/SceneManager.h"
#include "GameL/WinInputs.h"
#include "GameL/NetWork.h"
#include "GameL/SetWindow.h"
#include "GameL/Audio.h"

#include "CSceneMain.h"
#include "CSceneTitle.h"
#include "CConnectBackGround.h"

#include <time.h>

//使用するネームスペース
using namespace GameL;

void CConnectBackGround::Init()
{
	// 文字テクスチャを作成
	Font::SetStrTex((wchar_t*)L"接続中.マッチングしまた入れる部屋がありせんZKeyでTitleに戻対戦 秒");

	m_ConnectState = In_Connection;
	m_nFontAnimationFrame = 0;
	m_nGameStartTime = (unsigned int)0;
}

void CConnectBackGround::Action()
{
	// 接続中の処理
	if (m_ConnectState == In_Connection)
	{
		if (NetWork::Connect() == true)
		{
			// 接続成功
			m_ConnectState = Connection_Successful;

			if (NetWork::GetConnectKind() == NetWork::ConnectKind::Server)
			{
				while (1)
				{
					// ゲームが始まるまでの時間(待ち時間を付ける)
					// これによって開始時間を同期させる
					m_nGameStartTime = (unsigned int)time(NULL) + (unsigned int)5;

					if (NetWork::Send((char*)&m_nGameStartTime, sizeof(m_nGameStartTime))
						== SendState::Send_Successful)
					{
						break;
					}
				}
			}
			else
			{
				while (1)
				{
					// ゲームが始まるまでの時間を受け取る
					if (NetWork::Recv((char*)&m_nGameStartTime, sizeof(m_nGameStartTime))
						== RecvState::Recv_Successful)
					{
						break;
					}
				}
			}
		}
		else
		{
			// 接続失敗
			// クライアントの場合
			if (NetWork::GetConnectKind() == NetWork::ConnectKind::Client)
			{
				m_ConnectState = Connection_failure;

				// クライアントを削除
				NetWork::Close();
				NetWork::Delete();
			}
			// サーバーの場合
			else
			{
				if (Input::GetVKeyDown('Z') == true)
				{
					// サーバーを削除
					NetWork::Close();
					NetWork::Delete();

					Audio::Start(1);

					// タイトル画面へ
					Scene::SetScene(new CSceneTitle());
				}
			}
		}
	}
	// 接続完了後の処理
	else if (m_ConnectState == Connection_Successful)
	{
		// 残り時間が0秒になったら
		if (m_nGameStartTime <= time(NULL))
		{
			// ゲーム画面へ
			Scene::SetScene(new CSceneMain());
		}
	}
	// 接続失敗時の処理
	else if (m_ConnectState == Connection_failure)
	{
		if (Input::GetVKeyDown('Z') == true)
		{
			Audio::Start(0);

			// タイトル画面へ
			Scene::SetScene(new CSceneTitle());
		}
	}

	// アニメーションタイムを増やす
	m_nFontAnimationFrame++;

	// アニメーションが最大まで行ったら、初期化
	const int nAnimationMaxTime = 240;

	if (m_nFontAnimationFrame >= nAnimationMaxTime)
	{
		m_nFontAnimationFrame = 0;
	}
}

void CConnectBackGround::Draw()
{
	// 背景描画
	//カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F dst;//表示位置

	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = (float)Window::GetWidth(); // ウィンドウの幅
	dst.m_bottom = (float)Window::GetHeight();// ウィンドウの高さ

	Draw::Draw(0, &dst, c, 0.f);

	if (m_ConnectState == In_Connection)
	{
		wchar_t szConnectMessage[256] = L"接続中";
		const int nAnimationChangeNum = 60;		   // アニメーションの変化する基準値

		for (int i = 0; i < m_nFontAnimationFrame / nAnimationChangeNum; i++)
		{
			wcscat_s(szConnectMessage, 256, L"."); // 接続中に.を増やしたり、減らしたりするアニメーション
		}

		// ネットワーク接続画面と分かるように文字を描画
		Font::StrDraw(szConnectMessage, 0.f, 0.f, 120.f, c);

		Font::StrDraw(L"Z KeyでTitleに戻る", 100.f, 400.f, 60.f, c);
	}
	else if (m_ConnectState == Connection_Successful)
	{
		// 接続完了したときに表示するメッセージ
		Font::StrDraw(L"マッチングしました", 100.f, 400.f, 60.f, c);

		unsigned int nTime = m_nGameStartTime - (unsigned int)time(NULL);
		wchar_t szGameStartTime[256];
		swprintf_s(szGameStartTime, L"対戦まで %u秒", nTime);
		Font::StrDraw(szGameStartTime, 100.f, 600.f, 80.f, c);
	}
	else if (m_ConnectState == Connection_failure)
	{
		// サーバーが起動されていない時にクライアントを立ち上げてしまった場合、
		Font::StrDraw(L"入れる部屋がありません", 100.f, 200.f, 60.f, c);
		Font::StrDraw(L"Titleに戻ってください", 100.f, 400.f, 60.f, c);
		Font::StrDraw(L"Z KeyでTitleに戻る", 100.f, 600.f, 60.f, c);
	}
}