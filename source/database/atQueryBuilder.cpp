#pragma hdrstop
#include "atQueryBuilder.h"
//---------------------------------------------------------------------------

using namespace std;
string QueryBuilder::asString()
{
	return str();
}

const char* QueryBuilder::asCString()
{
	return str().c_str();
}

void QueryBuilder::clear()
{
	str("");
}
