//=============================================================================
//  MuseScore
//  Music Composition & Notation
//  $Id:$
//
//  Copyright (C) 2012 Werner Schweer
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License version 2
//  as published by the Free Software Foundation and appearing in
//  the file LICENCE.GPL
//=============================================================================

#include <QtTest/QtTest>

#include "libmscore/mscore.h"
#include "libmscore/score.h"
#include "libmscore/note.h"
#include "libmscore/chordrest.h"
#include "libmscore/accidental.h"
#include "libmscore/chord.h"
#include "libmscore/measure.h"
#include "libmscore/segment.h"
#include "libmscore/tremolo.h"
#include "libmscore/articulation.h"
#include "libmscore/sym.h"
#include "libmscore/key.h"
#include "libmscore/pitchspelling.h"
#include "mtest/testutils.h"

#define DIR QString("libmscore/test/")

using namespace Ms;

class TestTest : public QObject, public MTest {
      Q_OBJECT

      private slots:
      void initTestCase();
      void test();
};

void TestTest::initTestCase() {
      initMTest();
}

void TestTest::test() {
      MasterScore* score = readScore(DIR + QString("test.mscx"));
      score->doLayout();

      Measure* measure = score->firstMeasure();
      Segment* s = measure->first(SegmentType::ChordRest);
      Chord* c = static_cast<Chord*>(s->element(0));

      score->select(c);

      //score->cmdDoubleDuration();
      score->cmdHalfDuration();

      saveScore(score, QString("test-output.mscx"));
}

QTEST_MAIN(TestTest)

#include "tst_test.moc"