#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QNetworkConfiguration>
#include <QNetworkConfigurationManager>
#include <QNetworkSession>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QNetworkConfigurationManager ncm;
    ncm.updateConfigurations();
    qDebug()<<ncm.isOnline();
    qDebug()<<ncm.capabilities();
    //qDebug()<<ncm.
    QList<QNetworkConfiguration> netcfgList=ncm.allConfigurations(QNetworkConfiguration::Active);
    QStringList WiFisList;

    for(auto &x:netcfgList){
        if(x.bearerType()==QNetworkConfiguration::BearerWLAN)
        {
//            if(x.name()=="")
//                WiFisList.push_back("Unknown(Other Network)");
//            else {
                WiFisList.push_back(x.name());
                qDebug()<<"Name:"<<x.name()<<endl;
                qDebug()<<"Type: "<<x.type()<<endl;
                qDebug()<<"State:"<< x.state()<<endl;
                qDebug()<<"Purpose: "<<x.purpose()<<endl;
                qDebug()<<"Identifier: "<<x.identifier()<<endl;
                qDebug()<<"Is valid: "<<x.isValid()<<endl;
            //}
            //qDebug()<<x.type();
        }
    }

    qDebug()<<"Printing contents of wifilist"<<endl;
    qDebug()<<WiFisList<<endl;

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
