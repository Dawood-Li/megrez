#pragma once
#pragma comment(lib,"WINMM.LIB")
#include<Windows.h>
#include <string>

class Audio
{
public:
    Audio(std::string str);
    void loop();    /* 循环 */
    void once();    /* 一次 */
    void pause();   /* 暂停 */
    void resume();  /* 恢复 */
    void end();     /* 终止 */
private:
    void core(std::string s); /* 核心函数 */
    std::string music_name; /* 音频文件名 */
};

Audio::Audio(std::string str)
{
    music_name = str;
    core("open " + music_name + " alias msc");
}

void Audio::loop()   { core("play "   + music_name + " repeat"); }
void Audio::once()   { core("play "   + music_name); }
void Audio::pause()  { core("pause "  + music_name); }
void Audio::resume() { core("resume " + music_name); }
void Audio::end()    { core("close "  + music_name); }

void Audio::core(std::string s)
{
    size_t s_size = s.length() + 1;
    wchar_t* s2 = (wchar_t*)malloc(sizeof(wchar_t) * (s.length() - 1));
    mbstowcs_s(NULL, s2, s_size, s.c_str(), _TRUNCATE);
    mciSendString((LPWSTR)s2, NULL, 0, NULL);
}