#ifndef atResourceManagerH
#define atResourceManagerH
#include <string>
#include "core/atCoreExporter.h"
#include "mtkStringList.h"
//---------------------------------------------------------------------------

using std::string;
using mtk::StringList;

struct ResourceInfo
{
	string 		mName;
	string		mType;
                ResourceInfo(const string &name, const string& type)
                :
                mName(name),mType(type)
                {}

                ResourceInfo()
                :
                mType(_T(""))
                {}

                ResourceInfo(const ResourceInfo &info)
                {
                	*this = info;
                }

	ResourceInfo& operator=(const ResourceInfo& info)
	{
		mName = info.mName;
		mType = info.mType;
		return *this;
	}
};

class AT_CORE ResourceManager
{
    public:
        						            ResourceManager();
        virtual 				            ~ResourceManager();

        StringList				            loadAllResources();
        bool                                findResource(int res, const string& type);
        bool                                loadResourceDLL();

    protected:
        HANDLE 					            mModuleHandle;
        StringList							mResources;
        static bool                         EnumNames(HANDLE hModule, LPCTSTR lpType, LPTSTR lpName, LONG lParam);
        static bool                         EnumTypesFunc(HANDLE hModule, LPSTR lpType, LONG lParam);
};


#endif
