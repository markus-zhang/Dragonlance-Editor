#ifndef CPARSER_H_
#define CPARSER_H_

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "DebugTool.h"
#include "cProperty.h"

struct cNode 
{
	std::string m_Text;
	std::string m_Value;
	std::vector<cNode*> m_Child;
};

class cParser	
{
private:
	std::vector<std::string> m_Validate;
	std::string m_Text;
	int m_TextSize;
	
public:
	std::vector<cNode*> m_Tree;
	cParser();
	~cParser();

	void AddRoot(std::string text, std::string value);
	void AddLeaf(std::string text, std::string value, cNode* root);
	cNode* FindRoot(std::string text);

	bool Validate(std::string text);
	std::string GetTag(std::string text);
	std::string GetContent(std::string text);
	int GetTagLeftLocation(std::string text);	//< location
	int GetTagRightLocation(std::string text);	//> location
	int GetTagEndLocation(std::string text);	/// location
	std::string ExtractTag(std::string text);
	int ExtractTagValue(std::string lefttag);

	int Str2Int(std::string);
	inline void rtrim(std::string& s, char c) {
		if (s.empty())
			return;
		std::string::iterator p;
		for (p = s.end(); p != s.begin() && *--p == c;);
		/*if (*p != c)
			p++;*/
		s.erase(p, s.end());
	}
};

#endif