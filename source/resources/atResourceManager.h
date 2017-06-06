#ifndef atResourceManagerH
#define atResourceManagerH
//---------------------------------------------------------------------------

struct ResourceInfo
{
	int Type_Type;//0 = NUMBER,other string
	CString m_Name;
	CString	m_Type;
	CString m_ReadibleName;
	ResourceInfo(const CString &name, const CString& type):m_Name(name),m_Type(type),Type_Type(0){};
	ResourceInfo():m_Type(_T("")),Type_Type(0){};
	ResourceInfo(const ResourceInfo &info){*this = info;};
	ResourceInfo& operator= (const ResourceInfo& info)
	{
		m_Name = info.m_Name ;
		m_Type = info.m_Type ;
		m_ReadibleName = info.m_ReadibleName ;
		Type_Type = info.Type_Type ;
		return *this;
	}

};
class CRes
{
public:
	CRes();
	virtual ~CRes();
public:
	LPSTR LockRes();
	HRSRC GetLoadedRes();
	BOOL LoadAllResource();
	static BOOL EnumNames( HANDLE hModule, LPCTSTR lpType, LPTSTR lpName, LONG lParam);
	static BOOL EnumTypesFunc( HANDLE hModule, LPSTR lpType, LONG lParam);
	BOOL LoadResource();
	BOOL FindResource( int res,LPSTR type);
	void FreeIt();
	BOOL LoadExe();
	CString m_Path;
	CArray<ResourceInfo, ResourceInfo&> m_Infos;
protected:
	HRSRC hResLoad;     // handle to loaded resource
	HANDLE hExe;        // handle to existing .EXE file
	HRSRC hRes;         // handle/ptr. to res. info. in hExe
	//HANDLE hUpdateRes;  // update resource handle
	char *lpResLock;    // pointer to resource data
};


#endif
