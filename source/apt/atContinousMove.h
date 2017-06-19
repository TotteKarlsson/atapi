#ifndef abContinousMoveH
#define abContinousMoveH
#include "atMove.h"
//---------------------------------------------------------------------------

class AT_APT ContinousMove : public at::Move
{
    public:
        							ContinousMove::ContinousMove(const string& lbl, double v, double acc);
							        ~ContinousMove(){}
        virtual const string 		getTypeName() const {return "continousMove";}

        bool						isDone();
		bool 						start();
		virtual mtk::XMLElement*    addToXMLDocumentAsChild(mtk::XMLDocument& doc, mtk::XMLNode* docRoot);


    protected:

    private:

};
#endif
