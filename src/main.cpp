#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <include/cpuinfoparser.h>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    auto cpuInfoLst = CPUInfoParser::getCPUInfo();

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    for(unsigned int i=0;i<cpuInfoLst.size();i++)
    {
        //expose each CPUInfo as a seperate data model to the context

        QString modelName = QString::fromStdString("cpuInfoModel" + std::to_string(i));
        engine.rootContext()->setContextProperty(modelName,  QVariant::fromValue(cpuInfoLst[i]));
    }
    //add number of cpu cores to the context as a model
    engine.rootContext()->setContextProperty("cpuCount", QVariant::fromValue(cpuInfoLst.size()));

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
