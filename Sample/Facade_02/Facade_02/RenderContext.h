#pragma once

#include <Windows.h>
#include <iostream>
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Texture.h"

class VertexBuffer;
class IndexBuffer;
class Texture;

class RenderContext
{
public:
	// ���_�o�b�t�@��ݒ�B
	void SetVertexBuffer(VertexBuffer& vb)
	{
		m_vertexBuffer = &vb;
	}
	// �C���f�b�N�X�o�b�t�@��ݒ�B
	void SetIndexBuffer(IndexBuffer& ib)
	{
		m_indexBuffer = &ib;
	}
	// �e�N�X�`����ݒ�B
	void SetTexture(Texture& tex)
	{
		m_texture = &tex;
	}
	void Draw()
	{
		if (m_vertexBuffer == nullptr){
			MessageBoxA(nullptr, "���_�o�b�t�@���ݒ肳��Ă��܂���B", "�G���[", MB_OK);
			std::abort();
		}
		if (m_indexBuffer == nullptr) {
			MessageBoxA(nullptr, "�C���f�b�N�X�o�b�t�@���ݒ肳��Ă��܂���B", "�G���[", MB_OK);
			std::abort();
		}
		if (m_texture == nullptr) {
			MessageBoxA(nullptr, "�e�N�X�`�����ݒ肳��Ă��܂���B", "�G���[", MB_OK);
			std::abort();
		}
		std::cout << "�K�؂Ƀh���[�R�[�������s�ł��܂����B\n";
	}
private:
	VertexBuffer* m_vertexBuffer = nullptr;	// ���_�o�b�t�@�B
	IndexBuffer* m_indexBuffer = nullptr;	// �C���f�b�N�X�o�b�t�@�B
	Texture* m_texture = nullptr;			// �e�N�X�`���B
};

