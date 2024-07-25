#ifndef LOGGING_H
#define LOGGING_H

#include <string>
#include <ctime>
#include <vector>
#include <iostream>

using namespace std;

class logging
{
public:
	///
	/// Constructor 
	///
	logging(const string &);
	
	///
	///Create a log that get time and create a file named as ufc time,and write message in that file and also add log into a vector. Also erase old value in the vector 
	///
	void logger(const string& action);
	
	///
	///Change Log Type Frequency Maximum Log Number
	///
	void change_LogType_Freg_MaxLog(const string&, const int, const int);
	
	///
	///Return Log Turu
	///
	string get_LogTuru() const;
	
	///
	///Return Frequency of log
	///
	int get_Freg() const;
	
	///
	///Return maximum log that can be created
	///
	int get_MaxLog() const;
private:
	///
	///Log Turu
	///
	string name;
	
	///
	///Maximum log that can be created
	///
	int maximum_num;
	
	///
	///Frequency of log
	///
	int freg;
	
	///
	///Logs
	///
	vector<string> log;
	
	///
	///Get exact time and convert it ufc time
	///
	string getTime() const;
	
	///
	///Read config file
	///
	void read(const string&);
	
	///
	///Remove oldest value in the vector
	///
	void remove_Oldest();
	
	///
	///Set Log Type
	///
	void setLogTuru(const string&);
	
	///
	///Set Frequency
	///

	void set_Freg(const int&);
	
	///
	///Set maximum Log
	///
	void set_MaxLog(const int&);	
};

#endif
