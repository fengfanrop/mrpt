/* +---------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)               |
   |                          http://www.mrpt.org/                             |
   |                                                                           |
   | Copyright (c) 2005-2017, Individual contributors, see AUTHORS file        |
   | See: http://www.mrpt.org/Authors - All rights reserved.                   |
   | Released under BSD License. See details in http://www.mrpt.org/License    |
   +---------------------------------------------------------------------------+ */
#pragma once
#include <QGLWidget>

#include "mrpt/gui/CQtGlCanvasBase.h"
#include "mrpt/opengl/CSetOfObjects.h"
#include "mrpt/opengl/CPointCloud.h"
#include "mrpt/maps/CSimpleMap.h"
#include "mrpt/maps/CMultiMetricMap.h"


class CDocument;

class CGlWidget : public mrpt::gui::CQtGlCanvasBase
{
public:
	CGlWidget(QWidget* parent = nullptr);
	virtual ~CGlWidget();

	void fillMap(const mrpt::opengl::CSetOfObjects::Ptr &renderizableMap);
	void setSelected(const mrpt::math::TPose3D &pose);
	void setSelectedObservation(bool is);

	void setDocument(CDocument *doc);


private:
	mrpt::opengl::CSetOfObjects::Ptr m_map;
	CDocument* m_doc;
	bool m_isShowObs;

	float m_observationSize;
	QVector<mrpt::opengl::CPointCloud::Ptr> m_visiblePoints;
};
