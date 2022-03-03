#ifndef HELPER_H
#define HELPER_H

#include <ctime>
#include <string>
#include <sstream>
#include <fstream>

namespace Helper {

    template <class T>
    std::string ToString(const T&);

    struct DateTime {

        int d, m, y, H, M, S;

        DateTime(){
            time_t ms;
            time (&ms);

            struct tm *info = localtime(&ms);

            d = info->tm_mday;
            m = info->tm_mon+1;
            y = 1900 + info->tm_year;
            M = info->tm_min;
            H = info->tm_hour;
            S = info->tm_sec;
        }

        DateTime(int d, int m, int y, int H, int M, int S) : d(d), m(m), y(y), H(H), M(M), S(S) { }
        DateTime(int d, int m, int y) : d(d), m(m), y(y), H(0), M(0), S(0) { }

        DateTime Now() const {
            return DateTime();
        }

        std::string GetDateString() const {
            return std::string(d<10 ? "0" : "") + ToString(d) + std::string(m<10 ? ".0" : ".") + ToString(m) + "." + ToString(y);
        }

        std::string GetTimeString(const std::string &seperator=":") const {
            return std::string (H<10 ? "0" : "") + ToString(H) + std::string(M<10 ? "0" : "") + ToString(M) + std::string(S<10 ? "0" : "") + ToString(S);
        }

        std::string GetDateTimeString(const std::string &seperator=":") const {
            return GetDateString() + " " + GetTimeString(seperator);
        }
    };

    // this function only works with types which support insertion << operator
    template <class T>
    std::string ToString(const T &e){
        std::ostringstream s;
        s << e;
        return s.str();
    }

    void WriteAppLog(const std::string &s){
        std::ofstream file ("AppLog.txt", std::ios::app);
        file << "[" << Helper::DateTime().GetDateTimeString() << "]" << "\n" << s << std::endl << "\n";
    }

}


#endif // HELPER_H
