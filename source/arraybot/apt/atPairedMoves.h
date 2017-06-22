#ifndef abPairedMovesH
#define abPairedMovesH
#include "atATObject.h"
#include "atPairedMove.h"
#include <list>
#include "mtkINIFile.h"
//---------------------------------------------------------------------------
using std::list;
using mtk::IniFile;

typedef list<PairedMove> PMList;

//! The PairedMoves class is a container for PairedMoves
/*!
	Paired moves are saved in a INI file. Assign motors before 
    using.
*/
class AT_AB PairedMoves : public ATObject
{
    public:
                            			PairedMoves(const string& iniSection, IniFile& iniFile);
                            			~PairedMoves();
		PairedMove*						add(const PairedMove& s);
        bool							remove(const string& lbl);
		PairedMove*				        getPairedMove(const string& name);
        PairedMove*        		        getFirst() const;
        PairedMove*                     getNext() const;
        PairedMove*                     getPrevious() const;
        PairedMove*                     getCurrent() const;
        bool					        readINIParameters();
        bool					        writeINIParameters();

    protected:
		string							mIniSection;
        IniFile&						mIniFile;
		mutable PMList   				mPairedMoves;
    	mutable PMList::iterator 		mPairedMovesIter;
};
#endif