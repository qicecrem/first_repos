#include<iostream>

class Log
{
public:
	const int LogLevelWarning = 1;
	const int LogLevelError = 0;
	const int LogLevelInfo = 2;
private:
	int m_Loglevel;
public:
	void SetLevel(int level)
	{
		m_Loglevel = level;

	}
	void Warn(const char* message)
	{
		if (m_Loglevel >= LogLevelWarning) {
			std::cout << "[WARING}: " << message << std::endl;
		}
	}
	void Error(const char* message)
	{
		if (m_Loglevel >= LogLevelError) {
			std::cout << "{ERROR]: " << message << std::endl;
		}
	}
	void Info(const char* message)
	{
		if (m_Loglevel >= LogLevelInfo) {
			std::cout << "[INFO]:" << message << std::endl;

		}
	}

};
int main()
{
	Log log;
	log.SetLevel(log.LogLevelWarning);
	log.Warn("hello");
	log.Error("hello");
	log.Info("hello");
	std::cin.get();
}