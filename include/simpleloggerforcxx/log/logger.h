#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <mutex>

#define ESC 27

namespace LogUtils {

enum class Level {
  ERROR,
  WARNING,
  INFO
};

struct Setting {
  std::string log_file_dir = "log/logs.log";
  std::string date_type = "%Y-%m-%d %X"; // YYYY-MM-DD,HH:mm:ss 형태
  bool enable_endl = true;
};

class Logger {
  private:
    const std::string current_date_time();

    std::fstream log_file; //로그 파일용
    std::mutex mtx_lock; //출력 동기화용
    Setting setting;
  public:
    Logger();
    ~Logger();

    void log(const char*, Level&);

    void error(const char*);
    void error(const std::string&);

    void warning(const std::string &);
    void warning(const char*);

    void info(const char *);
    void info(std::string);

    void set_setting(Setting);
    Setting get_setting();

    void normal_format(const char *, ...);
};

}

#endif