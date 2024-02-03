#include <Novice.h>

#include "SceneManager.h"
#include "Title.h"

const char kWindowTitle[] = "LC1B_05_オザワ_ユウト_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	IManager* manager;

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	manager = new IManager(keys);
	manager->scene = new Title(manager);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		manager->Update();

		//敵の弾と自機との当たり判定

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		manager->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete manager;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
