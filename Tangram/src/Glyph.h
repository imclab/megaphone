//
//  Glyph.h
//  Tangram
//
//  Created by Elie Zananiri on 2012-10-26.
//
//

#pragma once

#include "ofMain.h"
#include "Limb.h"

//--------------------------------------------------------------
//--------------------------------------------------------------
class Glyph
{
    public:
        Glyph();
        ~Glyph();

        void addLimb(Limb limb);
        void clearLimbs();
        vector<Limb>& limbs();

        void update();
        void draw();
        void debug();

        ofVec2f& pos() { return _pos; }
        ofVec2f& vel() { return _vel; }
        ofVec2f& acc() { return _acc; }

        void setInitialCondition(ofVec2f pos, ofVec2f vel);
        void resetForce();
        void addForce(ofVec2f frc);
        void addDampingForce();
        void bounceOffWalls(bool bDampenCollision = true);
        void addRepulsionForce(ofVec2f frc, float radius, float scale);
        void addAttractionForce(ofVec2f frc, float radius, float scale);
        void addRepulsionForce(Glyph *glyph, float radius, float scale);
        void addAttractionForce(Glyph *glyph, float radius, float scale);

        void setFixed(bool fixed) { _bFixed = fixed; }
        bool isFixed() { return _bFixed; }

        bool animates();
        void setAnimates(bool animates);

        void setScale(float scale);
        void setRotation(float rotation);

        const ofRectangle& bounds() { return _bounds; }
        ofRectangle absBounds();

    private:
        ofVec2f _pos;
        ofVec2f _vel;
        ofVec2f _acc;

        bool    _bFixed;
        float   _damping;

        float   _scale, _targetScale;
        float   _rotation, _targetRotation;

        bool    _bAnimates;

        ofRectangle  _bounds;
        vector<Limb> _limbs;
};
