#include"Audio_Class.h"

int main()
{
	Audio bgm("C:/Users/dawood/Desktop/Samurai.mp3");
	bgm.loop();

	bool pause = 0;

	while (1)
	{
		///* 空格按下奇数次，暂停 */
		if (GetKeyState(VK_SPACE) == 1 && pause == 0)
		{
			bgm.pause();
			pause = 1;
		}

		if(GetKeyState(VK_SPACE) == 0 && pause == 1)
		{
			bgm.resume();
			pause = 0;
		}
	
		/* ESC键退出 */
		if (GetAsyncKeyState(VK_ESCAPE) < 0)
			break;

		Sleep(1);
	}

	bgm.end();

	return 0;
}