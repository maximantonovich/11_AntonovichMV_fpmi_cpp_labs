#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator> 

void put_num_in_vector(std::vector<int> &num);
long int sum_vector(const std::vector<int> &nums);
size_t count_of_num(const std::vector<int> &nums, int number);
size_t count_nums_with_condition(const std::vector<int> &nums);
void change_zeros(std::vector<int>& nums);
void print_vector(const std::vector<int> nums);
void add_interval(std::vector<int>& nums);
void replace_even(std::vector<int>& nums);
void delete_repeating(std::vector<int>& nums);



int main()
{
    try
    {
    std::vector<int> nums;
    put_num_in_vector(nums);

    std::cout << " you vector is: \n";
    print_vector(nums);

    long int sum = sum_vector(nums);
    size_t size = nums.size();

    std::cout << "\nsum of vector = " << sum << "\n";
    std::cout << "size of vector = " << size << "\n";

    std::cout << "write number which you want to count\n";
    int number;
    std::cin >> number;
    size_t count = count_of_num(nums, number);

    std::cout << "amount of number: " << number << " is: " << count << "\n";

    size_t count_condition = count_nums_with_condition(nums);

    std::cout << "amount of elements that appeal condition is: " << count_condition << "\n";

    change_zeros(nums);

    std::cout << "new vector after swapping zeros is: \n";
    print_vector(nums);


    add_interval(nums);
    std::cout << "new vector after adding interval is: \n";
    print_vector(nums);

    replace_even(nums);
    std::cout << "new vector after replacing even is: \n";
    print_vector(nums);

    delete_repeating(nums);
    std::cout << "new vector after deleting duplicates is: \n";
    print_vector(nums);




    return 0;
}
catch(const char* msg)
{
   std::cout << msg << "\n";
}
}


void print_vector(const std::vector<int> nums)
{
        if (nums.empty())
        {
            throw "vector is empty cant work with it\n";
        }
   
    std::ostream_iterator<int> it (std::cout, " ");

    std::copy(nums.begin(), nums.end(), it);
    std::cout << "\n";

    
}


void put_num_in_vector(std::vector<int> &nums)
{
    int n;
    std::cout << "write number that you want to put in vector(to stop: write non number)\n";
    while (std::cin >> n)
    {
        nums.push_back(n);
    }
    std::cin.clear();
    std::cin.ignore();
}


long int sum_vector(const std::vector<int> &nums)
{
    return accumulate(nums.begin(), nums.end(), 0);
}


size_t count_of_num(const std::vector<int> &nums, int number)
{
    return count(nums.begin(), nums.end(), number);
}


size_t count_nums_with_condition(const std::vector<int> &nums)
{
    std::cout << "write 1(<), 2(>), 3(<=), 4(>=), 5(==), to choose what condition you want to have\n";
    int condition;
    std::cin >> condition;
    switch (condition)
    {
    case 1:
    {
        std::cout << "write number which will be upper limit\n";
        int n;
        std::cin >> n;
        return std::count_if(nums.begin(), nums.end(), [n](int x) { return x < n; });
    }
    case 2:
    {
        std::cout << "write number which will be lower limit\n";
        int n;
        std::cin >> n;
        return std::count_if(nums.begin(), nums.end(), [n](int x){ return x > n; });
    }
    case 3:
    {
        std::cout << "write number which will be upper limit(including it)\n";
        int n;
        std::cin >> n;
        return std::count_if(nums.begin(), nums.end(), [n](int x) { return x <= n; });
    }
    case 4:
    {
        std::cout << "write number which will be lower limit(including it)\n";
        int n;
        std::cin >> n;
        return std::count_if(nums.begin(), nums.end(), [n](int x) { return x >= n; });
    }
    case 5:
    {
        std::cout << "write number which will be comparing to\n";
        int n;
        std::cin >> n;
        return std::count_if(nums.begin(), nums.end(), [n](int x) { return x == n; });
    }
    default:
        throw "got wrong condition\n";
    }
}


void change_zeros(std::vector<int>& nums)
{
    int mid_sum = std::accumulate(nums.begin(), nums.end(), 0) / nums.size();
    std::replace(nums.begin(), nums.end(), 0, mid_sum);
}


void add_interval(std::vector<int>& nums)
{
    std::pair<int, int> limits;
    std::cout << "write limits of interval(pls first < second)\n";

    std::cin.clear();
    std::cin.ignore();

    std::cin >> limits.first >> limits.second;
    if (limits.first < 0 || limits.second < 0 || limits.first >= nums.size() || limits.second >= nums.size())
    {
        throw "out of range";
    }
    int sum_interval = std::accumulate( nums.begin() + limits.first, nums.begin() + limits.second + 1, 0);
    for (std::vector<int>::iterator i = nums.begin() + limits.first; i != nums.begin() + limits.second + 1 ; ++i)
    {
        *i += sum_interval;
    }
    
}

void replace_even(std::vector<int>& nums)
{
    int diff_of_max_and_min = std::max_element(nums.begin(), nums.end()) - std::min_element(nums.begin(), nums.end());
    std::replace_if(nums.begin(), nums.end(), [](int x){return abs(x) % 2 == 0;}, diff_of_max_and_min);
}

void delete_repeating(std::vector<int>& nums)
{
    for (size_t i = 0; i < nums.size(); ++i) 
    {
        bool found = false;
        
        for (size_t j = 0; j < i; ++j) 
        {
            if (std::abs(nums[j]) == std::abs(nums[i])) 
            {
                found = true;
                break;
            }
        }

           if (found && i > 0) 
           {
            nums.erase(nums.begin() + i);
            --i;
        }
    }
    
}
