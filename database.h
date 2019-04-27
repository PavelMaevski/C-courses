#include "date.h"
#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <iomanip>
#include <cerrno>
#include <list>
#include <deque>
#include "queue"
#include <vector>
#include <algorithm>
#include "functional"
#include <utility>

#pragma once

using namespace std;

class Database {
public:
  Database() {};
  void Add(const Date&, const string&);
  void Find(const Date&) const;
  void Print(ostream&) const;
  string Last(const Date&) const;


	template<typename T>
	vector<string> FindIf(T func)const{
		vector<string> res;
//		vector<pair<Date, string>> output;
		ostringstream s;

//		for (auto it : events2)
//			if (func(it.first.first, it.first.second)) {
//				s << it.first.first << " " << it.first.second;
//				res.push_back(s.str());
//				s.str("");
//			}
		for (auto& event: events)
		{
			Date space = event.first;
			vector<string> out2(event.second.second.size());
			auto it = copy_if(event.second.second.begin(), event.second.second.end(), out2.begin(), [func, space](string s){
				return func(space, s);});
			  out2.resize(distance(out2.begin(),it));
			for (auto it2: out2)
			{
				s << event.first << " " << it2;
				res.push_back(s.str());
				s.str("");
			}
		}
		return res;
	}

	template<typename T2>
	int RemoveIf(T2 Func){
		vector<Date> erdates;//deque<Date> erdates;
		int removes=0;
		for(auto &event : events){
			Date space = event.first;
			auto partition = stable_partition(event.second.second.begin(),event.second.second.end(), [Func,space](string str){
				return (!Func(space,str));
			});
			removes += distance(partition,event.second.second.end());//count_if(partition,event.second.second.end(),[](string str){return true;});
			if (partition == event.second.second.begin()){
				erdates.push_back(event.first);
			}
			for (auto it = partition; it < event.second.second.end(); it++)
				event.second.first.erase(*it);

//			for (auto it = partition; it < event.second.second.end(); it++)
//				events2.erase(make_pair(space, *it));

			event.second.second.resize(distance(event.second.second.begin(),partition));//erase(partition,event.second.second.end());/**/


		}

		for (auto& it: erdates)
			events.erase(it);
		return removes;

	}

private:
  map<Date, pair<set<string>, vector<string>>> events;
//  map<pair<Date, string>, bool> events2;
};


