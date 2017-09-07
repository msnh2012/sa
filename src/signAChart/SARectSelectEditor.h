#ifndef SARECTSELECTEDITOR_H
#define SARECTSELECTEDITOR_H
#include <QObject>
#include "qwt_plot.h"
///
/// \brief 用于给图标添加矩形选框的事件过滤器
///
class SARectSelectEditor : public QObject
{
    Q_OBJECT
    Q_ENUMS(SelectionMode)
public:
    enum SelectionMode
    {
        SingleSelection ///< 当选
        ,AndSelection ///< 布尔与运算选择
        ,OrSelection ///< 布尔或运算选择
    };
    SARectSelectEditor(QwtPlot* parent = 0);
    virtual ~SARectSelectEditor();

    const QwtPlot *plot() const;
    QwtPlot *plot();

    virtual bool eventFilter(QObject *object, QEvent *event);

    SelectionMode selectionMode() const;
    void setSelectionMode(const SelectionMode &selectionMode);

private:
    bool pressed( const QPoint & p);
    bool moved( const QPoint & p);
    void released( const QPoint & p);
private:
    SelectionMode m_selectionMode; ///< 选框类型
};

#endif // SARECTSELECTEDITOR_H
