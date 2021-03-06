#ifndef HKBEXTRACTRAGDOLLPOSEMODIFIER_H_
#define HKBEXTRACTRAGDOLLPOSEMODIFIER_H_

#include <iostream>
#include <fstream>
#include <vector>
#include "src\hkx\hkbobject.h"
#include "src\hkx\modifier\hkbmodifier.h"

struct hkbextractragdollposemodifier : public hkbmodifier, std::enable_shared_from_this<hkbextractragdollposemodifier>
{
public:
	hkbextractragdollposemodifier() {}

	std::string GetAddress();

	std::string tempaddress;

	// variableBindingSet from hkbmodifier
	// userData from hkbmodifier
	// name from hkbmodifier
	// enable from hkbmodifier
	int poseMatchingBone0;
	int poseMatchingBone1;
	int poseMatchingBone2;
	bool enableComputeWorldFromModel;

	void regis(std::string id, bool isEdited);
	void dataBake(std::string filepath, vecstr& nodelines, bool isEdited);
	void connect(std::string filepath, std::string preaddress, int functionlayer, bool compare, hkbbehaviorgraph* graphroot);
	std::string getClassCode();
	void match(std::shared_ptr<hkbobject> counterpart);
	void newNode();

private:
	void parentRefresh();
	void nextNode(std::string filepath, int functionlayer, bool isOld, hkbbehaviorgraph* graphroot);
};

extern safeStringUMap<std::shared_ptr<hkbextractragdollposemodifier>> hkbextractragdollposemodifierList;
extern safeStringUMap<std::shared_ptr<hkbextractragdollposemodifier>> hkbextractragdollposemodifierList_E;

#endif