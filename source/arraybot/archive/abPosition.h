#ifndef abPositionH
#define abPositionH
#include "arraybot/atABExporter.h"
#include "core/atATObject.h"
#include "Math/mtkPoint.h"
#include <string>
//---------------------------------------------------------------------------

using std::string;
using mtk::Point;

//! A Position is a point in XYZ space.
/*!
The position can be named using the Label attribute
*/
namespace ab
{

class AT_AB Position : public ATObject
{
	public:
								Position(const string& lbl, double x, double y, double z);
								~Position();
		string					getLabel();
		void					setLabel(const string& l) {mLabel = l;}
        double					x() const;
        double 					y() const;
        double 					z() const;

	protected:
    	mtk::Point				mPosition;
        string					mLabel;
        double					mResolution;
};

}
#endif
