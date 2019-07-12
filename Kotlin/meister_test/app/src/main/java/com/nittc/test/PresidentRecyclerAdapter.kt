package com.nittc.test

import android.content.Intent
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.LinearLayout
import androidx.recyclerview.widget.RecyclerView
import kotlinx.android.synthetic.main.activity_contact_detail.view.*

internal const val EXTRA = "clicked_item"

class ContactRecyclerAdapter : RecyclerView.Adapter<ContactRecyclerAdapter.ContactViewHolder>() {
    inner class ContactViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView)

    override fun getItemCount() = Contacts.list.size

    override fun onBindViewHolder(holder: ContactViewHolder, position: Int) {
        val contact = Contacts.list[position]
        holder.itemView.textViewName.text = contact.name
        holder.itemView.setOnClickListener {
            val intent = Intent(holder.itemView.context, PresidentDetailActivity::class.java)
            intent.putExtra(EXTRA, position)
            holder.itemView.context.startActivity(intent)
        }
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ContactViewHolder {
        return ContactViewHolder(
            LayoutInflater.from(parent.context).inflate(
                R.layout.contact_item,
                parent,
                false
            ) as LinearLayout
        )
    }
}
