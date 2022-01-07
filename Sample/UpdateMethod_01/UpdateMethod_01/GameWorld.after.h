#pragma once

// step-1 ゲームワールドクラスの宣言を作成する。
#include "IGameObject.h"

/// <summary>
/// ゲームワールド
/// </summary>
class GameWorld
{
public:
	/// <summary>
	/// ゲームループを実行
	/// </summary>
	void ExecuteGameLoop();
	/// <summary>
	/// 新しいゲームオブジェクトを追加。
	/// </summary>
	/// <typeparam name="T">作成するゲームオブジェクトの型</typeparam>
	/// <typeparam name="...CtorArgs">コンストラクタに渡す可変長引数</typeparam>
	/// <param name="...ctorArgs">コンストラクタに渡す可変長引数</param>
	/// <returns></returns>
	template<class T, class... CtorArgs> 
	T* NewGameObject(CtorArgs... ctorArgs)
	{
		T* newObj = new T(ctorArgs...);
		m_gameObjectList.push_back(newObj);
		return newObj;
	}
	/// <summary>
	/// ゲームオブジェクトを破棄。
	/// </summary>	
	/// <param name="go">作成するゲームオブジェクト</param>
	void DeleteGameObject(IGameObject* go)
	{
		// DeleteGameObjectはUpdate関数を呼び出している最中に呼ばれる可能性が非常に高い。
		// そのため、ここでリストからの削除、メモリの解放を行うと不正メモリアクセスが起きる可能性が発生する。
		// そのため、ここではリストから削除をせずに、削除フラグのみを立てて、遅れて削除を行う。
		go->SetMarkDelete();
	}
private:
	std::list< IGameObject*> m_gameObjectList;			// ゲームオブジェクトのリスト。
};

