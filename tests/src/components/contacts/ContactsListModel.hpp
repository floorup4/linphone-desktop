#ifndef CONTACTS_LIST_MODEL_H
#define CONTACTS_LIST_MODEL_H

#include <QAbstractListModel>

#include "ContactModel.hpp"

// ===================================================================

class ContactsListModel : public QAbstractListModel {
  friend class ContactsListProxyModel;

  Q_OBJECT;

public:
  ContactsListModel (QObject *parent = Q_NULLPTR);

  int rowCount (const QModelIndex &) const {
    return m_list.count();
  }

  QHash<int, QByteArray> roleNames () const;
  QVariant data (const QModelIndex &index, int role) const;

public slots:
  ContactModel *mapSipAddressToContact (const QString &sipAddress);

private:
  QList<ContactModel *> m_list;
  QHash<linphone::Friend *, ContactModel* > m_friend_to_contact;
};

#endif // CONTACTS_LIST_MODEL_H