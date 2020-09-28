/*
Студент-программист: Горохов Михаил
Github: https://github.com/MarkRevantov/oop_exercise_01
Лабораторная работа № 01
Тема: Простые классы
Вариант: 14
Задание: Создать класс TimePoint для работы с моментами времени в формате «час:минута:секунда»

*/
#include <iostream>
#include <string>
//template <typename T>

class TimePoint {
    protected:
    int32_t seconds;
    int32_t minutes;
    int32_t hours;

    public:
    TimePoint(int32_t hours_, int32_t minutes_, int32_t seconds_) {
        set(hours_, minutes_, seconds_);
    }
    void set(int32_t hours_, int32_t minutes_, int32_t seconds_) {
        seconds = seconds_;
        minutes = minutes_;
        hours = hours_;

        minutes += seconds/60;
        seconds %= 60;

        hours += minutes/60;
        minutes %= 60;

        hours %= 24;
    }
    void set(int32_t seconds_) {
        set(0,0,seconds_);
    }
    void plus(int32_t hours_, int32_t minutes_, int32_t seconds_) {
        seconds += seconds_;
        minutes += minutes_;
        hours += hours_;

        minutes += seconds/60;
        seconds %= 60;

        hours += minutes/60;
        minutes %= 60;

        hours %= 24;
    }
    void plus(int32_t seconds_) {
        plus(0, 0, seconds_);
    }
    void plus(const TimePoint &time) {
        plus(time.hours, time.minutes, time.seconds);
    }
    void minus(int32_t hours_, int32_t minutes_, int32_t seconds_) {
        seconds = seconds - seconds_;
        while(seconds < 0) {
            minutes -= 1;
            seconds += 60;
        }
        minutes = minutes - minutes_;
        while(minutes < 0) {
            hours -= 1;
            minutes += 60;
        }
        while(hours < 0) {
            hours += 24;
        }
    }
    void minus(int32_t seconds_) {
        minus(0,0,seconds_);
    }
    void minus(const TimePoint &time) {
        minus(time.hours, time.minutes, time.seconds);
    }
    TimePoint get() {
        return *this;
    }
    int32_t get_sec() {
        return 60*(60*hours + minutes) + seconds;
    }
    int32_t get_min() {
        return 60*hours + minutes;
    }
    bool compare(const TimePoint &other_time) {
        return (hours == other_time.hours) && (minutes == other_time.minutes) && (seconds == other_time.seconds);
    }
    friend std::ostream& operator<< (std::ostream &out, const TimePoint &time){
        out << time.hours << ":" << time.minutes << ":" << time.seconds;
        return out;
    }

};
void help() {
    std::cout << "set1 (or set2) <hours> <minutes> <seconds>\n";
    std::cout << "set1sec (or set2sec) <seconds>\n";
    std::cout << "plus1 (or plus2) <hours> <minutes> <seconds>\n";
    std::cout << "plus1sec (or plus2sec) <seconds>\n";
    std::cout << "plus1to2\n";
    std::cout << "plus2to1\n";
    std::cout << "minus1 (or minus2) <hours> <minutes> <seconds>\n";
    std::cout << "minus1sec (or minus2sec) <seconds>\n";
    std::cout << "get1 (or get2)\n";
    std::cout << "get1sec (or get2sec)\n";
    std::cout << "get1min (or get2min)\n";
    std::cout << "compare\n";
    std::cout << "exit (or quit)\n";
    std::cout << "help (to get this help)\n";
}


int main() {
    std::cout << "Студент-программист: Михаил Горохов\nGithub: https://github.com/MarkRevantov/oop_exercise_01\n\n"; 
    help();
    std::string cmd;
    TimePoint time1(0,0,0);
    TimePoint time2(0,0,0);
    int32_t seconds, minutes, hours;
    while (true) {
        std::cout << ">>> ";
        std::cin >> cmd;
        if(cmd == "quit" || cmd == "exit") {
            break;
        }

        else if(cmd == "\n" || cmd == " " || cmd == "") continue;
        else if(cmd != "set1" && cmd != "set2" && cmd != "set1sec" && cmd != "set2sec" &&
                cmd != "plus1" && cmd != "plus2" && cmd != "plus1sec" && cmd != "plus2sec" &&
                cmd != "minus1" && cmd != "minus2" && cmd != "minus1sec" && cmd != "minus2sec" &&
                cmd != "plus1to2" && cmd != "plus2to1" && cmd != "get1" && cmd != "get2" &&
                cmd != "get1sec" && cmd != "get2sec" && cmd != "get1min" && cmd != "get2min" &&
                cmd != "compare" || cmd == "help") {
            std::cout << "\n--------" << cmd << "------\n";
            //help();
            continue;
        }
        else if (cmd == "set1" || cmd == "plus1" || cmd == "minus1" || cmd == "set2" || cmd == "plus2" || cmd == "minus2") {
            std::cin >> hours;
            std::cin >> minutes;
            std::cin >> seconds;
            
            if(cmd == "set1") time1.set(hours, minutes, seconds);
            else if(cmd == "set2") time2.set(hours, minutes, seconds);
            else if(cmd == "plus1") time1.plus(hours, minutes, seconds);
            else if(cmd == "plus2") time2.plus(hours, minutes, seconds);
            else if(cmd == "minus1") time1.minus(hours, minutes, seconds);
            else if(cmd == "minus2") time2.minus(hours, minutes, seconds);
        }
        else if (cmd == "set1sec" || cmd == "set2sec" || cmd == "plus1sec" || cmd == "plus2sec" || cmd == "minus1sec" || cmd == "minus2sec") {
            std::cin >> seconds;

            if(cmd == "set1sec") time1.set(seconds);
            else if(cmd == "set2sec") time2.set(seconds);
            else if(cmd == "plus1sec") time1.plus(seconds);
            else if(cmd == "plus2sec") time2.plus(seconds);
            else if(cmd == "minus1sec") time1.minus(seconds);
            else if(cmd == "minus2sec") time2.minus(seconds);
        }
        else if (cmd == "plus1to2") time2.plus(time1);
        else if (cmd == "plus2to1") time1.plus(time2);
        else if (cmd == "get1") std::cout << time1.get() << std::endl;
        else if (cmd == "get2") std::cout << time2.get() << std::endl;
        else if (cmd == "get1sec") std::cout << time1.get_sec() << " seconds\n";
        else if (cmd == "get2sec") std::cout << time2.get_sec() << " seconds\n";
        else if (cmd == "get1min") std::cout << time1.get_min() << " minutes\n";
        else if (cmd == "get2min") std::cout << time2.get_min() << " minutes\n";
        else if (cmd == "compare" && time1.compare(time2) == true) std::cout << " true\n";
        else if (cmd == "compare" && time1.compare(time2) == false) std::cout << " false\n";

    }
    return 0;
}