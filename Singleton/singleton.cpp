#include <vector>
#include <mutex>

class FileHandler
{
private:
    FileHandler(/* args */){};
    ~FileHandler(){};
    static FileHandler* instance = nullptr;
    static std::mutex mtx;

public:
    std::vector<std::string> getAllLines()
    {
        return new std::vector<std::string>;
    }
    static FileHandler* getInstance()
    {
        if(instance == nullptr)
        {
            mtx.lock();
            if(instance == nullptr)
            {
                instance = new FileHandler();              
            }
            mtx.unlock();
        }
        return instance;
    }
};

class Application
{
    int main()
    {
        auto foo = FileHandler.getInstance();
        auto allLinesVec = foo->getAllLines();
        return 0;
    }   
};