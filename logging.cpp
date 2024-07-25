#include "logging.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include "json.hpp"

using json = nlohmann::json;

logging::logging(const string &path){
	read(path);
}

void logging::logger(const string& action){
	string time = getTime();
	ofstream file(time + ".log", ios::app);
	file << action << endl;
	file.close();
	log.push_back(time + ".log");
	remove_Oldest();
}

void logging::remove_Oldest(){
	while( log.size() > maximum_num){
		// remove oldest value in vector  
		if( !log.empty()){
			remove(log.front().c_str());
			log.erase(log.begin());
		}
	}
}

string logging::getTime() const{
	time_t t = time(nullptr);
	tm* a = gmtime(&t);
	char buffer[250];
	strftime(buffer, sizeof(buffer), "%Y%m%dT%H%M%SZ", a);
    return string(buffer);
}



void logging::read(const string &path){
	ifstream file(path);
	
	if(!file.is_open()){
		cerr << "Config file cannot be opened" << endl;
		return;
	}
	
	file.seekg(0, ios::end);
    size_t size = file.tellg();
    if (size == 0) {
        cerr << "Config file is empty!" << endl;
        return;
    }
	
	file.seekg(0, ios::beg);
	
	json config;
    try {
        file >> config; // JSON verisini okuma
    } catch (json::parse_error& e) {
        cerr << "JSON okuma hatasý: " << e.what() << endl;
        return;
    }
	
	name = config["name"].get<string>();
	maximum_num = config["maximum_num"].get<int>();
	freg = config["freg"].get<int>();
}

void logging::change_LogType_Freg_MaxLog(const string &n, const int f, const int m){
	json changes;
	changes["name"] = n;
	changes["maximum_num"] = m;
	changes["freg"] = f;
	ofstream oFile("config.json");
	if (!oFile) {
        cerr << "Dosya açýlamadý!" << endl;
        return;
    }
	oFile << changes.dump(4);
	oFile.close();
	setLogTuru(n);
	set_Freg(f);
	set_MaxLog(m);
}

void logging::setLogTuru(const string& n){
	name = n;
}

void logging::set_Freg(const int& f){
	freg = f;
}

void logging::set_MaxLog(const int &m){
	maximum_num =m;
}

string logging::get_LogTuru() const{
	return name;
}

int logging::get_Freg() const{
	return freg;
}

int logging::get_MaxLog() const{
	return maximum_num;
}
