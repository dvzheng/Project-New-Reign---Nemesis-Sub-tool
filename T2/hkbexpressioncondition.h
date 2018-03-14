#ifndef HKBEXPRESSIONCONDITION_H_
#define HKBEXPRESSIONCONDITION_H_

#include <string>
#include <iostream>
#include <fstream>

struct hkbexpressioncondition
{
public:
	hkbexpressioncondition(std::string filepath, std::string id, std::string preaddress, int functionlayer, bool compare);

	void nonCompare(std::string filepath, std::string id);
	void Compare(std::string filepath, std::string id);
	void Dummy(std::string id);

	std::string GetAddress();
	bool IsNegate();
private:
	std::string address;
	std::string tempaddress;
	std::string expression;
	bool IsNegated = false;
};

extern void hkbExpressionConditionExport(std::string originalfile, std::string editedfile, std::string id);
#endif