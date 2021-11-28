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
	// 頂点バッファを設定。
	void SetVertexBuffer(VertexBuffer& vb)
	{
		m_vertexBuffer = &vb;
	}
	// インデックスバッファを設定。
	void SetIndexBuffer(IndexBuffer& ib)
	{
		m_indexBuffer = &ib;
	}
	// テクスチャを設定。
	void SetTexture(Texture& tex)
	{
		m_texture = &tex;
	}
	void Draw()
	{
		if (m_vertexBuffer == nullptr){
			MessageBoxA(nullptr, "頂点バッファが設定されていません。", "エラー", MB_OK);
			std::abort();
		}
		if (m_indexBuffer == nullptr) {
			MessageBoxA(nullptr, "インデックスバッファが設定されていません。", "エラー", MB_OK);
			std::abort();
		}
		if (m_texture == nullptr) {
			MessageBoxA(nullptr, "テクスチャが設定されていません。", "エラー", MB_OK);
			std::abort();
		}
		std::cout << "適切にドローコールを実行できました。\n";
	}
private:
	VertexBuffer* m_vertexBuffer = nullptr;	// 頂点バッファ。
	IndexBuffer* m_indexBuffer = nullptr;	// インデックスバッファ。
	Texture* m_texture = nullptr;			// テクスチャ。
};

