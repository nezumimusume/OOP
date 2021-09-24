#pragma once

// Enemyクラスの前方宣言
class Enemy;

// step-1 敵キャラクターのランダム移動クラスの宣言を実装する。
class EnemyRandomMove {
public:
	// 移動処理を実行する関数。
	// 引数に移動させる座標の参照を受け取る。
	void Execute(Vector3& pos);
private:
	Vector3 m_moveSpeed;	// 【注目】移動速度。
	int m_moveTimer = 0;	// 【注目】移動タイマー。
};

