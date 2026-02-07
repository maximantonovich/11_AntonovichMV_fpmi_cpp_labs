#include <iostream>
#include <string>
#include <map>  
#include <vector>
#include <iterator>
#include <fstream>
#include <sstream>
#include <utility>
#include <algorithm>


struct Mark {
    std::string subject_; // предмет
    size_t mark_; // оценка


    Mark(const std::string& subject, size_t mark) : subject_(subject), mark_(mark) {}


};


struct StudentData {
    std::string name_; // фамилия, инициалы
    size_t number_; // номер зачётки
    std::vector<Mark> marks_; // результаты сессии



    float get_rating() const
    {
        float rating = 0;

        for (const Mark& mark : marks_)
        {
            rating += mark.mark_;
        }

        rating /= marks_.size();

        return rating;
    }

};



std::map<size_t, StudentData> read_data_from_file(const std::string& input);
bool check_name(const std::string& name);

void write_sorted_by_num(const std::map<size_t, StudentData>& map);

void write_sorted_alphabetecally(const std::map<size_t, StudentData>& map);

void write_rating_in_range(const std::map<size_t, StudentData>& map);
std::pair<float, float> get_range();

void write_num_of_students_who_attended_lesson(const std::map<size_t, StudentData>& map);
std::string get_lesson();

std::vector<std::pair<std::string, size_t>> students_that_attend_each_lesson(const std::map<size_t, StudentData>& map);
void write_vector(const std::vector<std::pair<std::string, size_t>>& v);

std::vector<std::pair<std::string, float>> average_for_each_lesson(const std::map<size_t, StudentData>& map);
void write_vector(const std::vector<std::pair<std::string, float>>& v);

void write_max_grade_students(const std::map<size_t, StudentData>& map);

void write_students_with_bad_grade(const std::map<size_t, StudentData>& map);


int main() {
    setlocale(LC_ALL, "ru");
    const std::string input{ "input.txt" };

    try
    {
        std::map<size_t, StudentData> map = read_data_from_file(input);

        write_sorted_by_num(map);
        std::cout << "\n";

        write_sorted_alphabetecally(map);
        std::cout << "\n";

        write_rating_in_range(map);
        std::cout << "\n";

        write_num_of_students_who_attended_lesson(map);
        std::cout << "\n";

        std::vector<std::pair<std::string, size_t>> lessons = students_that_attend_each_lesson(map);
        std::cout << "количество студентов сдававших каждый предмет:\n";
        write_vector(lessons);
        std::cout << "\n";

        std::vector<std::pair<std::string, float>> v2 = average_for_each_lesson(map);
        std::cout << "средний балл по каждому предмету:";
        write_vector(v2);
        std::cout << "\n";
        write_max_grade_students(map);
        std::cout << "\n";
        write_students_with_bad_grade(map);

    }
    catch (const std::string& msg)
    {
        std::cerr << msg;
    }
    catch (const char* msg)
    {
        std::cerr << msg;
    }
    return 0;
}


std::map<size_t, StudentData> read_data_from_file(const std::string& input)
{
    std::ifstream in(input);
    if (!in.is_open())
    {
        throw "couldnt open input file";
    }
    if (in.peek() == EOF)
    {
        throw "file is empty";
    }


    std::map<size_t, StudentData> map;


    std::string str;
    while (getline(in, str))
    {
        std::stringstream line(str);
        std::string word;

        StudentData new_student;

        if (line >> word && check_name(word))
        {
            new_student.name_ = word;
        }
        else
        {
            continue;
        }

        size_t num;

        if (line >> num)
        {
            new_student.number_ = num;
        }
        else
        {
            continue;
        }

        std::string subject;
        size_t mark;

        while (line >> subject && line >> mark)
        {
            if (mark >= 0 && mark <= 10)
            {
            new_student.marks_.push_back(Mark(subject, mark));
            }
            else
            {
                throw ("Student: \"" + word + "\" has a problem with a mark\n");
            }
        }

        map.insert(std::make_pair(num, new_student));

    }
        if (map.empty())
        {
            throw "список студентов пуст или же на каждой строке допущена ошибка в формате";
        }
    in.close();
    return map;

}

bool check_name(const std::string& name)
{
    for (char a : name)
    {
        if (!((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')))
        {
            return false;
        }

    }
    return true;
}

void write_sorted_by_num(const std::map<size_t, StudentData>& map)
{
    std::cout << "сортировано по номеру зачётки\n";

    size_t num = 1;
    for (std::map<size_t, StudentData>::const_iterator i = map.begin(); i != map.end(); ++i)
    {
        std::cout << num++ << ": " << i -> first << " " << i -> second.name_ << "\n";
    }

}



void write_vector(const std::vector<std::pair<size_t, StudentData>>& v)
{
    size_t num = 1;
    for (std::vector<std::pair<size_t, StudentData>>::const_iterator i = v.begin(); i != v.end(); ++i)
    {
        std::cout << num++ << ": " << i->second.name_ << " номер зачётки: (" << i->first << ") средний балл: (" << i->second.get_rating() << ")\n";
    }
}

void write_vector(const std::vector<std::pair<std::string, size_t>>& v)
{
    size_t num = 1;
    for (std::vector<std::pair<std::string, size_t>>::const_iterator i = v.begin(); i != v.end(); ++i)
    {
        std::cout << num++ << ": " << i->first << " число студентов:(" << i->second << ")\n";
    }
}


void write_vector(const std::vector<std::pair<std::string, float>>& v)
{
    size_t num = 1;
    for (std::vector<std::pair<std::string, float>>::const_iterator i = v.begin(); i != v.end(); ++i)
    {
        std::cout << num++ << ": " << i->first << " средний балл:(" << i->second << ")\n";
    }
}





void write_sorted_alphabetecally(const std::map<size_t, StudentData>& map)
{


    std::vector<std::pair<size_t, StudentData>> v;
    if (!map.empty())
    {
       
        for (std::map<size_t, StudentData>::const_iterator i = map.begin(); i != map.end(); ++i)
        {
            v.push_back(*i);
        }

        std::sort(v.begin(), v.end(),
            [](const std::pair<size_t, StudentData> student_1, const std::pair<size_t, StudentData> student_2)
            {
                const std::string name_1 = student_1.second.name_;
                const std::string name_2 = student_2.second.name_;

                if (name_1 != name_2)
                {
                    return name_1 < name_2;
                }
                else
                {
                    double rating_1 = student_1.second.get_rating();
                    double rating_2 = student_2.second.get_rating();
                    return rating_1 > rating_2;
                }
            });


        
        std::cout << "сортировано по алфавиту\n";
        write_vector(v);
    }
    else
    {
        std::cout << "map is empty";
    }
}

void write_rating_in_range(const std::map<size_t, StudentData>& map)
{
    std::pair<float, float> range = get_range();

    if (range.first > range.second)
    {
        std::swap(range.first, range.second);
    }

    size_t num = 1;
    

    std::vector<std::pair<size_t, StudentData>> v;

    for (std::map<size_t, StudentData>::const_iterator i = map.begin(); i != map.end(); ++i)
    {
         float rating = i->second.get_rating();
         if (rating >= range.first && rating <= range.second)
         {
            v.push_back(*i);
         }
    }

    std::sort(v.begin(), v.end(),
        [](const std::pair<size_t, StudentData> student_1, const std::pair<size_t, StudentData> student_2)
        {
            double rating_1 = student_1.second.get_rating();
            double rating_2 = student_2.second.get_rating();
            return rating_1 > rating_2;
        });

    std::cout << "выведено в диапозоне:\n";
    write_vector(v);

    
}

std::pair<float, float> get_range()
{
    std::pair<float, float> range;
    std::cout << "пожалуйста введите диапозон среднего балла\n";
    std::cin >> range.first >> range.second;
    std::cout << "\n";
    return range;
}

void write_num_of_students_who_attended_lesson(const std::map<size_t, StudentData>& map)
{
    std::string lesson = get_lesson();
    size_t num = 1;
    std::cout << "студенты посещавшие предмет: " << lesson << "\n";
    for (std::map<size_t, StudentData>::const_iterator i = map.begin(); i != map.end(); ++i)
    {
        for (std::vector<Mark>::const_iterator it = i->second.marks_.begin(); it!= i->second.marks_.end(); ++it)
        {
            if (it->subject_ == lesson)
            {
                std::cout << num++ << ": " << i->first << " " << i->second.name_ << "\n";
            }
        }
    }
    if (num == 1)
    {
        std::cout << "никто не посещал данный предмет";
    }
}

std::string get_lesson()
{
    std::string lesson;
    std::cout << "введите предмет: ";
    std::cin >> lesson;
    std::cout << "\n";
    return lesson;
}


std::vector<std::pair<std::string, size_t>> students_that_attend_each_lesson(const std::map<size_t, StudentData>& map)
{
    std::vector<std::pair<std::string, size_t>> lessons;

    for (std::map<size_t, StudentData>::const_iterator i = map.begin(); i != map.end(); ++i)
    {
        for (std::vector<Mark>::const_iterator it = i->second.marks_.begin(); it != i->second.marks_.end(); ++it)
        {
            if (lessons.empty())
            {
                lessons.push_back(std::make_pair(it->subject_, 1));
                continue;
            }
            std::vector<std::pair<std::string, size_t>>::iterator iv = std::find_if(lessons.begin(), lessons.end(), [it](const std::pair<std::string, size_t> element) {return element.first == it->subject_; });
            if (iv == lessons.end())
            {
                lessons.push_back(std::make_pair(it->subject_, 1));
            }
            else
            {
                iv->second++;
            }
        }
    }
    return lessons;
}

std::vector<std::pair<std::string, float>> average_for_each_lesson(const std::map<size_t, StudentData>& map)
{
    std::vector<std::tuple<std::string, size_t, size_t>> lessons; // first-lesson, second-sum of grades, third- num of students

    for (std::map<size_t, StudentData>::const_iterator i = map.begin(); i != map.end(); ++i)
    {
        for (std::vector<Mark>::const_iterator it = i->second.marks_.begin(); it != i->second.marks_.end(); ++it)
        {
            if (lessons.empty())
            {
                lessons.push_back(std::make_tuple(it->subject_, it->mark_, 1));
                continue;
            }
            std::vector<std::tuple<std::string, size_t, size_t>>::iterator iv = std::find_if(lessons.begin(), lessons.end(), [it](const std::tuple<std::string, size_t, size_t> element) {return std::get<0>(element) == it->subject_; });
            if (iv == lessons.end())
            {
                lessons.push_back(std::make_tuple(it->subject_, it->mark_, 1));
            }
            else
            {
                std::get<1>(*iv) += it->mark_;
                std::get<2>(*iv)++;
            }
        }
    }

    std::vector<std::pair<std::string, float>> class_and_average;


    for (std::vector<std::tuple<std::string, size_t, size_t>>::iterator i = lessons.begin(); i != lessons.end(); ++i)
    {
        class_and_average.push_back(std::make_pair(std::get<0>(*i), std::get<1>(*i) / std::get<2>(*i)));
    }

    std::sort(class_and_average.begin(), class_and_average.end(), [](std::pair<std::string, float> class_1, std::pair<std::string, float> class_2)
        {
            return class_1.second > class_2.second;
        });

    return class_and_average;
}



void write_max_grade_students(const std::map<size_t, StudentData>& map)
{
    size_t sum_max = 0;
    for (std::map<size_t, StudentData>::const_iterator i = map.begin(); i != map.end(); ++i)
    {
        size_t sum_cur = 0;
        for (std::vector<Mark>::const_iterator it = i->second.marks_.begin(); it != i->second.marks_.end(); ++it)
        {
            sum_cur += it->mark_;
        }
            if (sum_cur > sum_max)
            {
                sum_max = sum_cur;
            }
    }
    std::cout << "студенты с максимальной суммой баллов: "<< sum_max <<"\n";
    size_t num = 1;
    for (std::map<size_t, StudentData>::const_iterator i = map.begin(); i != map.end(); ++i)
    {
        size_t sum_cur = 0;
        for (std::vector<Mark>::const_iterator it = i->second.marks_.begin(); it != i->second.marks_.end(); ++it)
        {
            sum_cur += it->mark_;
        }
            if (sum_max == sum_cur)
            {
                std::cout << num++ << ": " << i->first << " " << i->second.name_ << "\n";
            }
    }
}


void write_students_with_bad_grade(const std::map<size_t, StudentData>& map)
{
    size_t num = 1;
    std::cout << "студенты с плохими отметками:\n";
    for (std::map<size_t, StudentData>::const_iterator i = map.begin(); i != map.end(); ++i)
    {
        for (std::vector<Mark>::const_iterator it = i->second.marks_.begin(); it != i->second.marks_.end(); ++it)
        {
            if (it->mark_ <= 3)
            {
                std::cout << num++ << ": " << i->first << " " << i->second.name_ << "\n";
                break;
            }
        }
    }
}
