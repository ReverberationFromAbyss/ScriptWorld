module;

#ifdef _WIN32
#include <windows.h>
#endif // _WIN32

export module Utils;
import std;
using namespace std;

namespace ScriptingWorld {
namespace Utils {

string logfile{};

export void setLogFile(string name) {
  logfile = name;
  return;
}

export void log(const char *fileName, const int lines, const char *loginfo) {

  if (logfile.size() > 0) {
    ofstream fout(logfile, ios::app);
    fout << "[File:" << fileName << "/" << "Line:" << lines << "] " << loginfo
         << endl;
  } else {

#ifdef _WIN32
    HANDLE han = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD wOriginalColourAttrs;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

    GetConsoleScreenBufferInfo(han, &csbiInfo);
    wOriginalColourAttrs = csbiInfo.wAttributes;

    SetConsoleTextAttribute(han, FOREGROUND_GREEN | BACKGROUND_INTENSITY);
    cout << "[File:" << fileName << "/" << "Line:" << lines << "]";
    SetConsoleTextAttribute(han, wOriginalColourAttrs);
    cout << " " << loginfo << endl;
#endif // _WIN32

#ifdef _LINUX
    cout << "[File:" << fileName << "Line:" << lines << "] ";
    cout << loginfo << endl;
#endif // _LINUX
    return;
  }
}

} // namespace Utils
} // namespace ScriptingWorld
