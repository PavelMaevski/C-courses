#include "database.h"

void Database::Add(const Date& date, const string& event) {
//	if(find(events2[date].begin(), events2[date].end(),event)== events2[date].end()) {
//		events2[date].push_back(event);};// events3[make_pair(date,event)] = true;};
	if (event != "") {
	if (events.count(date) > 0) { if (events.at(date).first.find(event) == events.at(date).first.end())
		{ events.at(date).first.insert(event); events.at(date).second.push_back(event); };}// events2[make_pair(date, event)] = true;
	else { set<string> ev20 = {event}; vector<string> ev21 = {event};  events[date] = make_pair(ev20, ev21);}
	};// events2[make_pair(date, event)] = true;
};

void Database::Print(ostream& os) const
{
	for (auto& it: events)
		for (auto& it2 : it.second.second)
		{
			os << setw(4) << setfill('0') << it.first.GetYear();
			os << "-";
			os << setw(2) << setfill('0') << it.first.GetMonth();
			os << "-";
		    os << setw(2) << setfill('0') << it.first.GetDay() << " ";
			os << it2 << endl;
		}
};




string Database::Last(const Date &dt) const{
	if (events.size() == 0) { throw invalid_argument("");};
	auto prev = *events.begin();
	pair<Date, pair<set<string>, vector<string>>> prev2;
	ostringstream ostr;
	if(dt < prev.first){
		throw invalid_argument("");
	}
	if(events.find(dt)!=events.end()){
		ostr << dt << " " << *events.at(dt).second.rbegin();
					return ostr.str();
	}
	prev2 = prev;
	for(const auto &event : events){
		if(dt < (event.first) ){
			ostr << prev2.first << " " << *prev2.second.second.rbegin();
			return ostr.str();
		}
		prev2 = event;
	}
	ostr << prev2.first << " " << *prev2.second.second.rbegin();
	return ostr.str();
}
