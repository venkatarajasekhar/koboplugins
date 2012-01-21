#ifndef __TWEAKS_PLUGIN_H__
#define __TWEAKS_PLUGIN_H__

#include <QtGui>
#include "../../include/PluginInterface.h"
#include "TweaksWidget.h"

class TweaksPlugin : public QObject, public PluginInterface
{
	Q_OBJECT
	Q_INTERFACES(PluginInterface)

public:
	TweaksPlugin();
	~TweaksPlugin();

	QStringList mimeTypes();

	QWidget *reader(void* plugin_state, QWidget *parent = 0);
	ParserInterface *parser();

public slots:
    void windowChanged(int index);
    void patchMenu();
    void open(QString mimeType);

private:
    TweaksWidget *w;
    QSignalMapper mapper;
    QStackedWidget *sw;
    void *lastPatchedMenu;
};

#endif
