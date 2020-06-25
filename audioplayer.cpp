#include "audioplayer.h"
#include <QDir>
#include <QMediaPlayer>
#include <QMediaPlaylist>


static const QString s_curDir = QDir::currentPath() + "/";

AudioPlayer::AudioPlayer(QObject *parent)
    : QObject(parent)
    , backgroundMusic(NULL)
{
    // 创建一直播放的背景音乐
    QUrl backgroundMusicUrl = QUrl::fromLocalFile(s_curDir + "image/bgm.mp3");
    if (QFile::exists(backgroundMusicUrl.toLocalFile()))
    {
        backgroundMusic = new QMediaPlayer(this);
        QMediaPlaylist *backgroundMusicList = new QMediaPlaylist();

        QMediaContent media(backgroundMusicUrl);
        backgroundMusicList->addMedia(media);
        backgroundMusicList->setCurrentIndex(0);
        // 设置背景音乐循环播放
        backgroundMusicList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
        backgroundMusic->setPlaylist(backgroundMusicList);
    }
}

void AudioPlayer::startBGM()
{
    if (backgroundMusic)
        backgroundMusic->play();
}

void AudioPlayer::playSound(SoundType soundType)
{
    static const QUrl mediasUrls[] =
    {
        QUrl::fromLocalFile(s_curDir + "image/Towerplace.mp3"),
        QUrl::fromLocalFile(s_curDir + "image/lifelose.mp3"),
        QUrl::fromLocalFile(s_curDir + "image/enemydeath.mp3")
    };
    static QMediaPlayer player;

    if (QFile::exists(mediasUrls[soundType].toLocalFile()))
    {
        player.setMedia(mediasUrls[soundType]);
        player.play();
    }
}
