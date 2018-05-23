#ifndef atVCLUtilsH
#define atVCLUtilsH
#include <System.Classes.hpp>
#include <string>
#include "atUtilities.h"
//---------------------------------------------------------------------------
using std::string;


class PACKAGE ATWindowStructMessage
{
	public:
        Cardinal            Msg;
                            //
        int                 wparam;

                            //This is our data
        void*				lparam;
        LRESULT             Result;
};


//TImage utilities
PACKAGE int 				getImageWidth(TImage* imageCtrl);
PACKAGE int 				getImageHeight(TImage* imageCtrl);

PACKAGE double				getImageAspectRatio(TImage* imageCtrl);
PACKAGE double				getImageContainerAspectRatio(TImage* imageCtrl);
PACKAGE int                 getImageWidthFromHeight(TImage* imageCtrl);
PACKAGE int                 getImageHeightFromWidth(TImage* imageCtrl);

//List boxes
PACKAGE bool 	            updateListBoxItemCaption(TListBox* cb, int indx, const string& name);
PACKAGE int                 selectAndClickListBoxItem(TListBox* lb, TObject* p);
PACKAGE int                 selectAndClickListBoxItem(TListBox* lb, int itemIndex);
PACKAGE int                 selectAndClickListBoxItem(TListBox* lb, const string& name);

//Combo boxes
PACKAGE bool 	            updateComboBoxItemCaption(TComboBox* cb, int indx, const string& name);
PACKAGE string 	            getSelectedItem(TComboBox* lb);
PACKAGE int 	            selectItem(TComboBox* lb, const string& name, bool addItem = false);
PACKAGE int 	            selectAndClickComboBoxItem(TComboBox* lb, const string& name);

PACKAGE int 	            getCurrentUserID(TComboBox* mUserCB);

#endif
