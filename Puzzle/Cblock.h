#pragma once

//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�N���X�I�u�W�F�N�g�F�u���b�N
class Cblock : public CObj
{
	public:
		Cblock() {};
		~Cblock() {};
		void Init();
		void Action();
		void Draw();
	private:
		float m_f_px;
		float m_f_py;
		float m_f_vx;
		float m_f_vy;
};