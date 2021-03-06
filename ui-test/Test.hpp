#include <QThread>
#include <QApplication>
#include <QWidget>
#include "../qt/ConcreteSettings.hpp"

class SettingsStub : public cadencii::ConcreteSettings{
public:
    SettingsStub(){
        isUnitTest = true;
    }
};

class Test : public QObject{
    Q_OBJECT

public:
    Test();

private slots:
    /**
     * @brief 読み込みに失敗するVSQファイルが渡されてもクラッシュしないこと
     */
    void openVsqFileWithException();

    /**
     * @brief Controller::removeSelectedEvents のテスト
     */
    void removeSelectedEvents();

    /**
     * @brief 長さが 0 のイベントがあった場合でもクラッシュしないこと
     */
    void avoidCrashByZeroLengthEvent();

    /**
     * @brief 書き込みに失敗する場合であってもクラッシュしないこと
     */
    void exportAsVSQFileWithException();

    /**
     * @brief 書き込みに失敗する場合であってもクラッシュしないこと
     */
    void exportAsMusicXmlWithException();

    /**
     * @brief トラックリストのクリックによって、トラックが切り替わること
     */
    void changeTrackIndex();

    /**
     * @brief A test for ConcretePropertyView::fetchProperty.
     */
    void propertyViewFetchProperty();

    /**
     * @brief Can open xvsq file.
     */
    void openXvsq();

    /**
     * @brief Should not crash when invalid xvsq file was opened.
     */
    void openXvsqWithException();
};
