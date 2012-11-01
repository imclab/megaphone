//
//  Page.cpp
//  FloatingPage
//
//  Created by Elie Zananiri on 2012-11-01.
//
//

#include "FlatPage.h"

FlatPage::FlatPage()
{
    ty = 0;
    pause = 0;

    static int pageSize = 20;
    path.moveTo(ofPoint(-pageSize, 0, -pageSize));
    path.lineTo(ofPoint(-pageSize, 0, pageSize));
    path.lineTo(ofPoint(pageSize, 0, pageSize));
    path.lineTo(ofPoint(pageSize, 0, -pageSize));
}

void FlatPage::update()
{
    if (pause > 0) --pause;
    else {
        static int apex = 200;

        // move up and down
        ty += 0.01;
        pos.y = ABS(sin(ty)) * apex;

        // twirl slower as you reach the apex
        float twirlInc = (apex - pos.y) * 0.001;
        twirl += twirlInc;

        // tilt more as you reach the apex
        tilt = sin(twirlInc) * 2;

        if (pos.y <= 1) {
            // pause for a bit
            pause = 30;
        }
    }
}

void FlatPage::draw()
{
    ofPushMatrix();
    ofTranslate(pos);
    ofRotate(RAD_TO_DEG * twirl, 0, 1, 0);
    ofRotate(RAD_TO_DEG * tilt, 1, 0, 1);

    path.draw();
    
//    static int pageSize = 20;
//    ofSetColor(200, 0, 0);
    
//    ofBeginShape();
//    ofVertex(-pageSize, 0, -pageSize);
//    ofVertex(-pageSize, 0, pageSize);
//    ofVertex(pageSize, 0, pageSize);
//    ofVertex(pageSize, 0, -pageSize);
//    ofEndShape(true);

    ofPopMatrix();
}