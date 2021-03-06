#pragma hdrstop
#include "atVCLUtils.h"
#include "dslVCLUtils.h"
#include "dslLogger.h"
//---------------------------------------------------------------------------

namespace at
{

using namespace dsl;
using namespace Poco;

int getCurrentUserID(TComboBox* mUserCB)
{
	int i = mUserCB->ItemIndex;

    if(i > -1)
    {
    	return * ((int*) mUserCB->Items->Objects[i]);
    }

	return  -1;
}

//---------------------------------------------------------------------------
double getCurrentImageWidth(TImage* img)
{
    //This function assumes stretch is proportional
    double origW = img->Picture->Width;
    double origH = img->Picture->Height;
    double imageR = origW / origH;

    double containerW = img->Width;
    double containerH = img->Height;
    double containerR = containerW / containerH;

    if(containerR > imageR)
    {
    	return containerH * imageR;
    }
    else
    {
    	return containerW;
    }
}

//---------------------------------------------------------------------------
double getCurrentImageHeight(TImage* img)
{
    //This function assumes stretch is proportional
    double origW = img->Picture->Width;
    double origH = img->Picture->Height;
    double imageR = origW / origH;

    double containerW = img->Width;
    double containerH = img->Height;
    double containerR = containerW / containerH;

    if(containerR > imageR)
    {
        return containerH;
    }
    else
    {
    	return containerW /imageR;
    }
}

double getImageAspectRatio(TImage* imageCtrl)
{
    double w = imageCtrl->Picture->Width;
	double h = imageCtrl->Picture->Height;

    if(w == 0 || h == 0)
    {
        Log(lError) << "Can't calculate aspect ratio for image!";
        return -1;
    }

    if( w > h)
    {
        return w / h;
    }
    else if (h > w)
    {
        return h/w;
    }
    else
    {
        return 1.0;
    }
}

double getImageContainerAspectRatio(TImage* imageCtrl)
{
    double w = imageCtrl->Width;
	double h = imageCtrl->Height;

    if(w == 0 || h == 0)
    {
        Log(lError) << "Can't calculate aspect ratio for image container!";
        return -1;
    }

    if( w > h)
    {
        return w / h;
    }
    else if (h > w)
    {
        return h/w;
    }
    else
    {
        return 1.0;
    }
}

int getImageWidthFromHeight(TImage* imageCtrl)
{
    //This apply to as scaled, proprtional image, assuming its height is the same as
    //its container
    double originalWidth(imageCtrl->Picture->Width);
    double originalHeight(imageCtrl->Picture->Height);

    double currentHeight = imageCtrl->Height;
    double currentWidth = currentHeight / ( originalHeight / originalWidth);

    return currentWidth;
}

int getImageHeightFromWidth(TImage* imageCtrl)
{
    //This apply to as scaled, proprtional image, assuming its height is the same as
    //its container
    double originalWidth(imageCtrl->Picture->Width);
    double originalHeight(imageCtrl->Picture->Height);

    double currentWidth = imageCtrl->Width;
    double currentHeight = currentWidth * ( originalHeight / originalWidth);

    return currentHeight;
}


//void populateUsersCB(TComboBox* mUserCB, ATDBServerSession& ses)
//{
//    //Fetch data
//    mUserCB->Clear();
//    RecordSet *rs =  ses.getUsers();
//    if(!rs->rowCount())
//    {
//        Log(lInfo) << "There are no users...";
//    }
//    else
//    {
//        int cols = rs->columnCount();
//        int rows = rs->rowCount();
//
//        using Poco::Data::RowIterator;
//        // iterate over all rows and columns
//        for (RowIterator it = rs->begin(); it != rs->end(); ++it)
//        {
//            Poco::Data::Row& row = *it;
//            string user(row[1].convert<std::string>());
//            int *userId = new int(row[0].convert<int>());
//            mUserCB->Items->AddObject(user.c_str(), (TObject*) userId );
//            Log(lInfo) <<user;
//        }
//        mUserCB->ItemIndex = 0;
//    }
//}
//
//void populateUsersCB(TComboBox* mUserCB, ATDBClientDBSession& ses)
//{
//    //Fetch data
//    mUserCB->Clear();
//    RecordSet *rs =  ses.getUsers();
//    if(!rs->rowCount())
//    {
//        Log(lInfo) << "There are no users...";
//    }
//    else
//    {
//        int cols = rs->columnCount();
//        int rows = rs->rowCount();
//
//        // iterate over all rows and columns
//        for (RecordSet::Iterator it = rs->begin(); it != rs->end(); ++it)
//        {
//            Poco::Data::Row& row = *it;
//            string user(row[1].convert<std::string>());
//            int *userId = new int(row[0].convert<int>());
//            mUserCB->Items->AddObject(user.c_str(), (TObject*) userId );
//            Log(lInfo) <<user;
//        }
//        mUserCB->ItemIndex = 0;
//    }
//}

bool updateListBoxItemCaption(TListBox* lb, int indx, const string& name)
{
	if(indx > -1 && indx < lb->Count)
    {
		lb->Items->Strings[indx] = vclstr(name);
        return true;
    }
    return false;
}

int selectAndClickListBoxItem(TListBox* lb, TObject* p)
{
	if(!lb)
    {
    	return -1;
    }

	//find the item in the list box;
	for(int i = 0; i < lb->Count; i++)
    {
    	if(lb->Items->Objects[i] == p)
        {
        	lb->Selected[i] = true;
            lb->OnClick(NULL);
            return i;
        }
    }
    return -1;
}

int selectAndClickListBoxItem(TListBox* lb, int itemIndex)
{
	if(!lb)
    {
    	return -1;
    }

	if(itemIndex < lb->Count && itemIndex > -1)
    {
    	lb->Selected[itemIndex] = true;
        lb->OnClick(NULL);
    }

    return itemIndex;
}

int selectAndClickListBoxItem(TListBox* lb, const string& item)
{
	if(!lb)
    {
    	return -1;
    }

	//find the item in the list box;
	for(int i = 0; i < lb->Count; i++)
    {
    	if(compareStrings(stdstr(lb->Items->Strings[i]) ,item))
        {
        	lb->Selected[i] = true;
            lb->OnClick(NULL);
            return i;
        }
    }
    return -1;
}

string getSelectedItem(TComboBox* cb)
{
	if(!cb || cb->ItemIndex == -1)
    {
    	return gEmptyString;
    }
	return stdstr(cb->Items->Strings[cb->ItemIndex]);
}

int selectItem(TComboBox* cb, const string& name, bool addItem)
{
	if(!cb)
    {
    	return -1;
    }

	//find the item in the list box;
	for(int i = 0; i < cb->Items->Count; i++)
    {
    	if(compareStrings(stdstr(cb->Items->Strings[i]) , name))
        {
        	cb->ItemIndex = i;
            return i;
        }
    }

    //Seem the item did not exist.
    if(addItem)
    {
    	cb->AddItem(vclstr(name), NULL);
	    return selectItem(cb, name, addItem);
    }

    return -1;
}

int selectAndClickComboBoxItem(TComboBox* cb, const string& name)
{
	if(!cb)
    {
    	return -1;
    }

	//find the item in the list box;
	for(int i = 0; i < cb->Items->Count; i++)
    {
    	if(compareStrings(stdstr(cb->Items->Strings[i]) , name))
        {
        	cb->ItemIndex = i;
            return i;
        }
    }
    return -1;
}

bool updateComboBoxItemCaption(TComboBox* cb, int indx, const string& name)
{
	if(indx > -1 && indx < cb->Items->Count)
    {
		cb->Items->Strings[indx] = vclstr(name);
        return true;
    }
    return false;
}

}
