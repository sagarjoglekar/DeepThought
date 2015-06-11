package com.twilio.interview.cloudinfrastructure.model.impl;

import com.twilio.interview.cloudinfrastructure.model.Host;
import com.twilio.interview.cloudinfrastructure.model.HostSize;
import com.twilio.interview.cloudinfrastructure.model.HostState;

public class HostImpl implements Host {

    @Override
    public String getId() {
        // TODO Auto-generated method stub
        return null;
    }

    @Override
    public String getType() {
        // TODO Auto-generated method stub
        return null;
    }

    @Override
    public String getDescription() {
        // TODO Auto-generated method stub
        return null;
    }

    @Override
    public HostSize getSize() {
        // TODO Auto-generated method stub
        return null;
    }

    @Override
    public HostState getState() {
        // TODO Auto-generated method stub
        return null;
    }

    @Override
    public boolean isActive() {
        // TODO Auto-generated method stub
        return false;
    }

    @Override
    public void boot() throws IllegalStateException {
        // TODO Auto-generated method stub

    }

    @Override
    public void activate() throws IllegalStateException {
        // TODO Auto-generated method stub

    }

    @Override
    public void deactivate() throws IllegalStateException {
        // TODO Auto-generated method stub

    }

    @Override
    public void shutdown() throws IllegalStateException {
        // TODO Auto-generated method stub

    }

}
